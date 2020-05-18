#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
int i,j,ec,fg,ec2;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;
void Create();
void Append();
void Delete();
void rainbow();
void Display();
int main()
{    rainbow();
	  cout<<"\n\t\t*** TEXT EDITOR ***\n\n";
	  cout<<"1.Create  \t\t    2.Display\n\n";
	  cout<<"3.Append  \t\t    4.Delete\n\n";
	  cout<<"5.Exit";
	  cout<<"\n\n\tMENU\n\t-----\n ";
	  cout<<"\n\tEnter your choice: ";
	  cin>>ec;
	  system("cls");
	  switch(ec)
	  { case 1: Create();
	  	        break;
	  	case 2: Display();
	  	        break;
	    case 3: Append();
	            break;
	    case 4: Delete();
	            break;
	    case 5: exit(0);
	  }
       return 0;
}
void rainbow()
{
    int gdriver = DETECT,gmode;

    int x, y, i;

   initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    x = getmaxx() / 2;

    y = getmaxy() / 2;
    for (i=30; i<200; i++)

    {
         delay(100);
         setcolor(i/10);
         arc(x, y, 0, 180, i-10);

    }

}
void Create()
{
    int b;
    fp1=fopen("temp.txt","w");
  cout<<b<<"\n\tEnter the text and press '.' to save";
   while(1)
   {  c=getchar();
   	  fputc(c,fp1);
   	  if(c == '.')
   	   {  fclose(fp1);
   	   	  cout<<"\n\tEnter then new filename: ";
   	   	  cin>>fn;
   	   	  fp1=fopen("temp.txt","r");
   	   	   fp2=fopen(fn,"w");
   	   	   while(!feof(fp1))
   	   	   {  c=getc(fp1);
   	   	   	  putc(c,fp2);// j)
   	   	   }
   	   	   fclose(fp2);
   	   	   break;
   	    }
   }
}
void Display()
{  cout<<"\n\tEnter the file name: ";
   cin>>fn;
   fp1=fopen(fn,"r");
   if(fp1==NULL)
   {  cout<<"\n\tFile not found!";
   	  goto end1;
   }
   while(!feof(fp1))
   {  c=getc(fp1);
   	  cout<<c;
   }
   end1: fclose(fp1);
   cout<<"\n\n\tPress any key to continue...";
   getch();
}
void Delete()
 { cout<<"\n\tEnter the file name: ";
   cin>>fn;
   fp1=fopen(fn,"r");
   if(fp1==NULL)
   { cout<<"\n\tFile not found!";
   	 goto end2;
   }
   fclose(fp1);
   if(remove(fn)==0)
   {cout<<"\n\n\tFile has been deleted successfully!";
   	 goto end2;
   }
   else
   cout<<"\n\tError!\n";
  end2: cout<<"\n\n\tPress any key to continue...";
getch();
}
void Append()
{ cout<<"\n\tEnter the file name: ";
  cin>>fn;
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {  cout<<"\n\tFile not found!";
  	 goto end3;
  }
  while(!feof(fp1))
  { c=getc(fp1);
    cout<<c;
  }
  fclose(fp1);
  cout<<"\n\tType the text and press 'Ctrl+S' to append\n";
  fp1=fopen(fn,"a");
   while(1)
  {  c=getch();
  	 if(c==19)
  	 goto end3;
  	 if(c==13)
  	 { c='\n';
  	   cout<<"\nt";
  	    fputc(c,fp1);
  	 }
  	 else
     { cout<<c;
       fputc(c,fp1);
     }
  }
  end3: fclose(fp1);
   getch();
}
