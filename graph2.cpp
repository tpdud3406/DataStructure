#include<iostream>
#include<fstream>
#include"graph2.h"

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

/*************** 행렬 크기 반환 함수 *********/
// n x n의 경우 n 반환
int Graph::GetSize(void){
    return n;
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
/*********가중치가 최소가 되는 정점 반환하는 함수 *********/
int Graph::Choose(int n) {
    // Choose는 S[i]=false 이고, dist[u] = minimum dist[w]가 되는 u를 반환
    int min;
    for (int i = 0; i < n; i++) {
        if (!S[i]) min = i;
    }
    for (int i = 0; i < n; i++) {
        if ((!S[i]) && (dist[min] > dist[i])) min = i;
    }
    return min;
}

/**********최단 경로 출력 함수(Dijkstra 최단경로 알고리즘) ********/
// 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
void Graph::PrintShortestPathWeight(int s){
    // 간선의 길이 graph[i][j], 최단 경로 dist[i] 
    // S[i]: 정점 i가 S에 포함되어 있으면 S[i] = true, 아니면 S[i] = false로 표현하는 boolean 배열
    dist = new int[n];
    S = new bool[n];

    // 초기화
    for(int i = 0; i < n; i++){
        S[i] = false;
        dist[i] = graph[s][i];
    }

    S[s] = true; // 시작 정점 s 포함
    dist[s] = 0; // 시작점이므로 가중치 0

    //Dist[w]=min{Dist[w], Dist[u] + weight[u, w]}
    for(int i = 0; i < n-2; i++){ // 정점 s로부터 n-1개 경로를 결정
        int u = Choose(n);
        S[u] = true;

        for(int j = 0; j < n; j++){ // 최소값 찾기
            if(!S[j] && dist[u] + graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << endl;
    }

    return;
}
