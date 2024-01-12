#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto desync_untie = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

int chocolate(const int& N, const int& K, vector<int>& p) {
  /**
   * Let c(i, j) be the maximum profit at day j with at most i transactions.
   * The solution to the problem is finding c(k, n).
   * Everyday we make a decision to either sell a previously bought chocolate or
   * do nothing. If we do nothing then the maximum profit doesn't change and is
   * equal to c(i, j - 1). If we decide to sell then:
   * Let j = m : 0 <= m <= j. To sell the chocolate at day m we must've bought it
   * on a previous day [0...m - 1] say day b : 0 <= b <= j - 1.
   * We are trying to find the b that maximizes p(m) - p(b) + c(i - 1, b - 1).
   * For every such day m we must check all N remaining days to maximize the profit
   * for all K transactions. This leads to O(kn^2).
   * However p(m) is constant for the current i iteration so we are really trying to
   * find the b that maximizes c(i - 1, b - 1) - p(b). So for every loop we can 
   * keep the maximum c(i - 1, b - 1) - p(b) we have found.
   * So for every j iteration we just have to add p(m) to the previously found
   * maximum c(i - 1, b - 1) - p(b). Therefore for every i iteration we have to
   * check N days once. Therefore the time complexity is O(nk).
    */
  vector<vector<int>> c(K + 1, vector<int>(N, 0));
  for (size_t i = 1; i <= K; i++) {
      int loopMax = -p[0]; // c(i - 1, 0) - p(0) = 0 - p(0)
    for (size_t j = 1; j < N; j++) {
      // The max between not selling and selling.
      c[i][j] = max(c[i][j - 1], p[j] + loopMax);
      // The max profit with at most i - 1 transactions and j - 1 days 
      // and we buy at day j.
      loopMax = max(loopMax, c[i - 1][j - 1] - p[j]);
    }
  } 
  return c[K][N - 1];
}

int main(int argc, char *argv[]) {
  int N, K, prices, answer;
  string outcome;
  vector<int> arr;
  if (argc > 1) {
    string input_path = "./test_cases/input";
    string output_path = "./test_cases/output";
    string ext = ".txt";
    int num = 1;
    ifstream input_file, output_file;
    while (1) {
      input_file.open(input_path + to_string(num) + ext);
      if (input_file.good()) {
        input_file >> N;
        input_file >> K;
        arr.reserve(N);
        while (input_file >> prices) {
          arr.push_back(prices);
        }
        input_file.close();
        int solution = chocolate(N, K, arr);
        arr.clear();
        output_file.open(output_path + to_string(num) + ext);
        output_file >> answer;
        output_file.close();
        if (solution == answer) {
          outcome = "Correct.";
        } else {
            outcome = "Wrong.";
            cout << "Answer: " << solution << " - Expected: " << answer << '\n';
          }
        cout << "Test case - " << num << ": " << outcome << '\n';
        num++;
      } else {
        break;
      }
    }
  } else {
    cin >> N;
    cin >> K;
    arr.reserve(N);
    while(cin >> prices) {
      arr.push_back(prices);
    }
    int solution = chocolate(N, K, arr);
    cout << solution << '\n';
  }
  return 0;
}
