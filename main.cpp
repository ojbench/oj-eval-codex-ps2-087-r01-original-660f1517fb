#include <iostream>
#include <vector>

using namespace std;

namespace {

void fill_leaf_states(int depth, long long balls, vector<int>& states, int index) {
    if (depth == 1) {
        states[index] = static_cast<int>(balls & 1LL);
        return;
    }

    long long left_balls = (balls + 1) / 2;
    long long right_balls = balls / 2;

    fill_leaf_states(depth - 1, left_balls, states, index * 2);
    fill_leaf_states(depth - 1, right_balls, states, index * 2 + 1);
}

int last_ball_position(int depth, long long balls) {
    int node = 1;
    for (int level = 1; level < depth; ++level) {
        if (balls & 1LL) {
            node = node * 2;
            balls = (balls + 1) / 2;
        } else {
            node = node * 2 + 1;
            balls /= 2;
        }
    }
    return node;
}

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int depth;
    long long balls;
    cin >> depth >> balls;

    int leaf_count = 1 << (depth - 1);
    vector<int> states(leaf_count, 0);
    fill_leaf_states(depth, balls, states, 0);

    cout << last_ball_position(depth, balls) << '\n';
    for (int index = 0; index < leaf_count; ++index) {
        if (index > 0) {
            cout << ' ';
        }
        cout << states[index];
    }
    cout << '\n';
    return 0;
}
