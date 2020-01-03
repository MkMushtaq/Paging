
				//gcc filename.c -lm
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
int find(int x,int a[],int n)
{
    for(int i=0;i<n;i++)
    {
    if(x==a[i])
        {
        return x;
        }
    }
    return x+1;
}
struct entry
	{
	int pfn;
	int valid_bit;	
	int protection_bit;
	int dirtyBit;	
	int modeBit;
	};

long int convert_binary(int x)
	{
	int r,i=0;
	long int sum=0;
	while(x>0)
		{
		r = x%2;
		sum = sum + r*(pow(10,i));
		x = x/2;
		i++;	
		}
	return sum;
	} 



int main()
{
//struct address a[64];
srand(time(0));
int i=0,n,ins;
int c[5];
printf("Enter the size of the array:");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
    {
    a[i]=0;
    }
for(i=0;i<5;i++)
    {
    c[i]=0;
    }


i=0;

while(i<n)
    {
    ins=rand()%65536;

    if(find(ins,a,n)==ins+1 && i<n )
        {

                if(ins<13108)
                    {
                    if(c[0]-n/5<0)
                        {
                        c[0]=c[0]+1;
                        a[i]=ins;
                        i++;
                        }
                    }
                else if(ins>13107 && ins<26215)
                    {
                    if(c[1]-n/5<0)
                        {
                        c[1]=c[1]+1;
                        a[i]=ins;
                        i++;
                        }
                    }
                else if(ins>26214 && ins<39322)
                    {
                    if(c[2]-n/5<0)
                        {
                        c[2]=c[2]+1;
                        a[i]=ins;
                        i++;
                        }
                    }
                else if(ins>39321 && ins<52429)
                    {
                    if(c[3]-n/5<0)
                        {
                        c[3]=c[3]+1;
                        a[i]=ins;
                        i++;
                        }
                    }
                else if(ins>52428 && ins<65317)
                    {
                    if(c[4]-n/5<0)
                        {
                        c[4]=c[4]+1;
                        a[i]=ins;
                        i++;
                        }
                    }

        }
    printf("\n\n");
    }

for(i=0;i<n;i++)
    {
    printf("%d\n",a[i]);
    }

printf("\n\n");
struct entry PTE[64];
for(i=0;i<64;i++)
	{
	int frame_no=rand()%16384;
	PTE[i].pfn = frame_no;
	PTE[i].valid_bit = rand()%2;
	PTE[i].protection_bit = rand()%2;
	}
for(i=0;i<n;i++)
	{
	int virtual_address = a[i];
	int VPN_MASK=64512,OFFSET_MASK=1024;
	int VPN = ((virtual_address) & VPN_MASK)  >> 10;
	int OFFSET = (virtual_address) & (OFFSET_MASK);
	printf("VPN:%d        %ld\n",VPN,convert_binary(VPN));
	printf("OFFSET:%d       %ld\n",OFFSET,convert_binary(OFFSET));


	clock_t start,end;
	start = clock();
	int PFN=(PTE[VPN].pfn);
	if(PTE[VPN].valid_bit==0)
		printf("SEGMENTATION_FAULT\n");
	else if(PTE[VPN].protection_bit==0)
		printf("PROTECTION_FAULT\n");
	else
		{
		
		char s1[20],s2[20];
		printf("PFN:%d   %ld\n",PFN,convert_binary(PFN));
		long int physical_address = atoi(s1);
		printf("Physical address:%ld%ld \n",convert_binary(PFN),convert_binary(OFFSET));
		}

	end = clock();
	double t=((double)end-start)/CLOCKS_PER_SEC;
	printf("Time lapsed:%f\n\n\n",t);
	}

}

