#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char S[100];
int count = 0,calls=0;
void allSubsets(int pos,int len,char *subset,int size)
{
	calls++;
	int i;
	if(pos == size)
	{	
		count++;
		//printf("{ ");
		for(i=0;i<len;i++)
		{
			if(i>=size)
			{
				//printf("%c ",subset[i]);
			}
		}
		//printf("}\n");
		return;
	}
	subset[len] = S[pos];
	allSubsets(pos+1,len+1,subset,size);
	allSubsets(pos+1,len,subset,size);
}

int main() 
{ 
	FILE *f1,*f2;
    char set[100];
    int n,i,j=0;
    f1 = fopen("recsubsetscalls.txt","a");
    f2= fopen("recsubscounts.txt","a");
    printf("Enter size of set and set elements: ");
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%c ",&set[i]);
    	S[i] = set[i];
    }
    //printf("\n\nThe subsets are:\n");
    allSubsets(0,strlen(set),set,strlen(S));
    fprintf(f1,"%d %d\n",n,calls);
    fprintf(f2,"%d %d\n",n,count);
    fclose(f1);
    fclose(f2);
    return 0; 
    
}
