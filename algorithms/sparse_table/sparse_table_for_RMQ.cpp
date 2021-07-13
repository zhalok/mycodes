int log[MAXN+1];
log[1] = 0;
for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;
    
// computing the log values because its safer than builtin log function of math.h    
    
    
int st[MAXN][K + 1];

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        
// building sparse table 
        
        
        
int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - ( (1 << j) - 1 )][j]);

//quering 

// why it is true ? look from st[L][j] we are getting a value and from st[R-((1<<j)-1)][j] we are getting two segments which can be overlapping or adjacent 
// so if we get the minimum of them thats the answer 
