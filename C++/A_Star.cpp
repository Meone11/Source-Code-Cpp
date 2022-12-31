#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 10;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int g[N][N];
int dist[N][N];

struct Node {
  int x, y;
  int f;

  bool operator<(const Node& other) const {
    return f > other.f;
  }
};

void A_star(int start_x, int start_y, int end_x, int end_y) {
  priority_queue<Node> q;
  unordered_map<int, unordered_map<int, bool>> visited;

  dist[start_x][start_y] = g[start_x][start_y];
  q.push({start_x, start_y, dist[start_x][start_y]});

  while (!q.empty()) {
    Node curr = q.top();
    q.pop();

    if (curr.x == end_x && curr.y == end_y) {
      cout << "Jarak terpendek: " << dist[end_x][end_y] << endl;
      return;
    }

    if (visited[curr.x][curr.y]) continue;
    visited[curr.x][curr.y] = true;

    for (int i = 0; i < 4; i++) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (visited[nx][ny]) continue;

      int new_dist = dist[curr.x][curr.y] + g[nx][ny];
      if (new_dist < dist[nx][ny]) {
        dist[nx][ny] = new_dist;
        int f = new_dist + abs(end_x - nx) + abs(end_y - ny);
        q.push({nx, ny, f});
      }
    }
  }
}

int main() {
  int g[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };
  int dist[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = 1e9;
    }
  }

//   int start_x = 0, start_y = 0, end_x = 9, end_y = 9;

  A_star(0, 0, 9, 9);

  return 0;
}

