answering q queries: 


while(q--)

{

int left,right;
int len = right-left+1;

int K = log(len);

ll sum = 0;

for(int j=k;j>=0;j--)
if((1<<j)<=len)
{ 

sum += sparse_table[left][j];
left += (1<<j);

}

cout<<sum<<endl;


}
