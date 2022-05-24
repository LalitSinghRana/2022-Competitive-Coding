vector<int> Solution::solve(vector<int> &A) {

    int n = A.size();

    for (int i = 0; i < n; i++)

    {

        int cnt = count(A.begin(), A.begin() + i + 1, A[i]);

        if (cnt > 1)

        {

            auto found = find(A.begin(), A.begin() + i + 1, A[i]) - A.begin();

            A[found]++;

        }

    }

    return A;

}
