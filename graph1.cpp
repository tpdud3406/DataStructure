#include<iostream>
#include<fstream>
#include"graph1.h"

using namespace std;

/*********인접 행렬 저장 함수***********/
// 인자로 받은 파일명으로 파일에 있는 가중치 행렬을 읽어서 멤버 변수로 저장
void Graph::LoadMatrix(std::string& filename){
    ifstream fin;
    fin.open(filename);

    // 행렬 크기 저장
    fin >> n; 

    // 행렬 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> graph[i][j];
        }
    }
    fin.close();
    
    return;
}


/**********인접 행렬 출력 함수*************/
void Graph::PrintMatrix(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return;
}