//
// Created by egjlmn1 on 1/17/20.
//

#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include "SearchingAlgorithms/Searchers/BestFirstSearch.h"
#include "SearchingAlgorithms/Searchable/MatrixSearchable.h"


void MyTestClientHandler::handleClient(int client_socket) {
    string data;
    char buffer[1024];
    while (true) {
        for (int i=0;i<1024;i++)
            buffer[i] = 0;
        // read from socket
        int valread = read(client_socket, buffer, 1024);
        if (valread < 1) {
            cerr << "error" << endl;
            close(client_socket);
            return;
        }
        if (recv(client_socket, buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0) {
            // if recv returns zero, that means the connection has been closed:
            cerr << "error" << endl;
            close(client_socket);
            break;
        }

        data.append(buffer);
        if (data.size() > 4) {
            if (data.substr(data.size() - 4, 4) == "end\n")
            {
                break;
            }
        }
        //do something with the buffer
    }

    create_problem(data, client_socket);
    close(client_socket);
}

void MyTestClientHandler::create_problem(const string& data, int socket) {

    vector<string> lines = split(data, '\n');
    int size = lines.size() - 3;
    double* matrix_problem = new double[size * size];
    for (int i = 0; i < size; i++) {
        string str = lines[i];
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
        int j = 0;
        for (const string& s : split(str, ',')) {
            matrix_problem[i * size + j] = atof(s.c_str());
            j++;
        }
    }

    pair<pair<int, int>, pair<int, int>> start_end;
    vector<string> point = split(lines[size], ',');
    cout << lines[size] << endl;
    start_end.first = pair<int, int>(atoi(point[0].c_str()), atoi(point[1].c_str()));
    point = split(lines[size + 1], ',');
    start_end.second = pair<int, int>(atoi(point[0].c_str()), atoi(point[1].c_str()));


    MatrixSearchable *searchable = new MatrixSearchable(size, size, matrix_problem);

    vector<State<string>*> solution;
    string to_send;
    int index = 0;
    while (index < (solution.size() - 1)) {
        auto state = solution[index];

        int i1 = searchable->GetLengthByState(solution[index]);
        int j1 = searchable->GetWidthByState(solution[index]);

        index++;
        auto state2 = solution[index];
        int i2 = searchable->GetLengthByState(solution[index]);
        int j2 = searchable->GetWidthByState(solution[index]);


        if (i1 > i2) {
            //up
            to_send.append("Up (");
        } else if (i2 < i1) {
            //down
            to_send.append("Down (");
        } else if (j1 > j2) {
            //left
            to_send.append("Left (");
        } else {
            //right
            to_send.append("Right (");
        }
        to_send.append(to_string(state2->GetCost()));
        to_send.append("), ");
    }
    send(socket, to_send.substr(0, to_send.size()-2).c_str(), to_send.size() - 2, 0);
}

vector <string> MyTestClientHandler::split(string data, char to_split) {
    vector<string> lines;
    string line;
    for (char c : data) {
        if (c == to_split) {
            lines.push_back(line);
            line = "";
        } else {
            line.append(1, c);
        }
    }
    if (!line.empty()) {
        lines.push_back(line);
    }
    return lines;
}

