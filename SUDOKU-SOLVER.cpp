#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

int a,n;
int x[100],y[100];
int s[100][100];
int w[100][100];

int check(int i,int j,int z)
  {
  	int m,p,flag=1,u,v,e,f;
  	for(m=0;m<a;m++)
  	  if(i==x[m])
  	     for(p=m;p<=m;p++)
  	        if(j==y[p]) {flag=2; return 2;}
  	        
  	        
  	for(m=1;m<=n-1;m++)
	  if(i<m*sqrt(n)) break;
	for(p=1;p<=n-1;p++)
	  if(j<p*sqrt(n)) break;
    
    m=(m-1)*sqrt(n);
    p=(p-1)*sqrt(n);
	
	for(u=m,e=0;e<sqrt(n);u++,e++)
	  for(v=p,f=0;f<sqrt(n);v++,f++)
	    if(s[u][v]==z) flag=0; 
        
		
	for(p=0;p<n;p++)
	  if(s[i][p]==z) flag=0;
        
	  
	for(m=0;m<n;m++)
	  if(s[m][j]==z) flag=0;
	  
	return flag;    	        
  }
  
 
 void place(int i,int j)
   { 
    int k=1,z,flag=0,m,p,a,b;
    int r,t,flag2,q;
    
    
    
    
    if(s[i][j]==0)  flag2=1;
    
 
   
    
    if(i>=n||i<0) 
    {  
      printf("\n");
       printf("\nThe Solved Sudoku Is:\n\n");
    for(r=0;r<n;r++)
	    {for(t=0;t<n;t++)
	       printf(" %d",s[r][t]);
	     printf("\n");
      }	      
       exit(0); 
        	}

       	
  
   	
    
   	
   	
   	if(s[i][j]!=0) k=2;
   	
   
    
 
   	 if(s[i][j]==n||s[i][j]==0) z=1;
   	 else z=s[i][j]+1;
        
  
   	
   	while(k<=n)
   	  { 
   	    if(check(i,j,z)==2)
   	        {
			   
           flag=2;
           break;
           
   	        
		    }
   	            
   	    else if(check(i,j,z)==1)
   	       {
            if(z==w[i][j])

                    { 
            s[i][j]=0;
            w[i][j]=0;
       
        if(j==0)         
                {
                  i=i-1;
                  j=n-1;
                }    
        else 
            j=j-1;
                   
       for(a=i;a>=0;a--)
          {for(b=j;b>=0;b--)
              if(check(a,b,z)==2) continue;
              else place(a,b);
          if(b==-1) j=n-1;
          }  
                
                     
	   
		}
			       s[i][j]=z; 
            
   	         flag=1;
   	         break;
		   }
	    else if(check(i,j,z)==0)
		    {
		     if(z!=n-1) 	
			    { 
				z=(z+1)%n;
		        k=k+1;
		        }
		     else 
			    {
			     z=z+1;
				 k=k+1;	
				}   
			}		
   }
   	  	
		 
		 
   if(flag==2)
    {
      if(j==n-1)
   	            place(i+1,0);
   	        else
   	            place(i,j+1); 
    }
    
	if(flag==1)
	  {
	    if(j==n-1)
	     {
         if(flag2==1) w[i][j]=z;      
                
          place(i+1,0);}
	   else
	     {
           if(flag2==1) w[i][j]=z;      
                    
                place(i,j+1); }
       }
		 	     
    else if(flag==0)
	   {
	   	s[i][j]=0;
      w[i][j]=0;
	   
      if(j==0) 
                {
                  i=i-1;
                  j=n-1;
                }    
        else 
            j=j-1;
                   
       for(a=i;a>=0;a--)
          {for(b=j;b>=0;b--)
              if(check(a,b,z)==2) continue;
              else place(a,b);
          if(b==-1) j=n-1;
          }    
        
    
		}
	
   } 

int main()
  {
  	int i,j;
  	printf("\nenter the size=");
  	scanf("%d",&n);
    printf("\nenter the sudoku:\n");
  	for(i=0;i<n;i++)
  	  for(j=0;j<n;j++)
  	     scanf("%d",&s[i][j]);
  	     
  	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     if(s[i][j]!=0)
		   {x[a]=i;
		    y[a]=j;
		    a++;
			 }
			
  
	place(0,0);
	
	printf("\nthe solved sudoku is:\n");
	for(i=0;i<n;i++)
	  {for(j=0;j<n;j++)
	     printf(" %d",s[i][j]);
	   printf("\n");
      }
      
     getch(); 
  }
