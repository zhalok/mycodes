void sparseTable(int n)
{

    int m = log(n)+1;

    for (int i = 0; i < n; i++)
        sparse_table[i][0] = v[i];

    // it means starting from index i of len 2^0=1 is the value itself

    for (int j = 1; j <= m; j++)
        for (int i = 0; i + (1 << j) < n; i++)
            sparse_table[i][j] = sparse_table[i][j - 1] + sparse_table[i + (1 << (j - 1))][j - 1]

    // here it means that the value of segment (from i of len 2^j) is equal to the sum of segment ( from i of len (2^j)/2 which is 2^(j-1) + from i+2^(j-1) of len 2^(j-1) )
}
