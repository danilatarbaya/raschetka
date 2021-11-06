
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n; // число ребер
    int s; // количество вершин
    int r; // начальная точка
    int a, b, d;
    cout << "Введите количество вершин";
    cin >> s;

    cout << "Введите количество ребер графа";
    cin >> n;

    cout << "Введите граф";

    vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {

        cin >> a >> b >> d;
        v[a][b] = v[b][a] = d;
    }

    cout << "Введите начальную точку";
    cin >> r;

    bool visite[100];
    int dist[100];

    for (int i = 1; i < n; i++) {

        visite[i] = false;
        dist[i] = INT_MAX;
    }

    dist[r] = 0;
    visite[r] = true;

    queue<int>q;
    q.push(r);
    while (!q.empty()) { // пока очередь не пуста 
        int vetrex = q.front(); // достаем первую вершину из очереди 
        q.pop(); // удаляем данную вершину из очереди, чтоб алгоритм корректно завершился
       
        for (int j = 1; j < v[vetrex].size(); j++) { // помещяем все вершины смежные с вершиной  в очередь

            if (!visite[j] && v[vetrex][j] && v[vetrex][j] + dist[vetrex] < dist[j]) { // вершина еще не посещена, у вершины есть ребро

                dist[j] = v[vetrex][j] + dist[vetrex]; // обновление расстояния
                q.push(j);
            }
        }
    }

    for (int j = 1; j <= s; j++) {

        cout << "До вершины " << j << " Минимальное расстояние = " << dist[j] << endl;
    }

}