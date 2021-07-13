void dfs(int node)
{
	
	
	for(int i=0;i<adj[node].size();i++)
	if(adj[node][i]!=parent[node])
	{
		level[adj[node][i]]=level[node]+1;
		dfs(adj[node][i]);
	}

}

void create_sparse_table()
{
   for(int j=1;j<=log2(n);j++)
   {
	   for(int i=1;i<=n;i++)
	   {
		   int par=sparse_table[i][j-1];
		   if(par!=-1)
		   sparse_table[i][j]=sparse_table[par][j-1];
	   }
   }
}

int lca(int a,int b)
{
	if(level[b]<level[a]) swap(a,b);
	int d=level[b]-level[a];
	while(d>0)
	{
		int jump=log2(d);
		b=sparse_table[b][jump];
		d-=(1<<jump);
	}

	if(a==b) return a;

    for(int i=log2(n);i>=0;i--)
	if(sparse_table[a][i]!=-1&&sparse_table[a][i]!=sparse_table[b][i])
	{
		a=sparse_table[a][i];
		b=sparse_table[b][i];
	}
	return parent[a];



}
