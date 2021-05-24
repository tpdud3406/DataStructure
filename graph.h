/*********** Graph 클래스 *************/

class Graph{
private:
    int n;
    int graph[100][100]; // 크게 선언
public:
    void LoadMatrix(std::string& filename);
    int GetSize(void); // 행렬 크기 반환(n x n의 경우 n 반환)
    void PrintMatrix(void); // 인접 행렬 출력
    void PrintShortestPathWeight(int s); // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
};

