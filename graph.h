/*********** Graph 클래스 *************/

class Graph{
private:
    int n;
    int graph[100][100]; // 크게 선언
public:
    void LoadMatrix(std::string& filename);
    void PrintMatrix(void);
};
