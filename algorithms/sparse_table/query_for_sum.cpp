answering q queries: 

int sparse_table[n][k];

while(q--)

{

int left,right;
int len = right-left+1;

ll sum = 0;

for(int j=k;j>=0;j--)
if((1<<j)<=len) // that means we have found a valid length
{ 

sum += sparse_table[left][j]; // so we are taking it into the sum
left += (1<<j); // we are updating the left 

}

cout<<sum<<endl;


}


