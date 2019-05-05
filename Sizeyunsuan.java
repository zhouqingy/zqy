package xunsuan;
import java.util.*;
public class Sizeyunsuan {

	public static char  Operator()
	{
		Random random =new Random();
		int i=0;
		char ch='+';
		i=random.nextInt()%4+1;
		switch(i)
		{
		case 1:  ch= '+';break;
		case 2:  ch= '-';break;
		case 3:  ch= '*';break;
		case 4:  ch= '/';break;
		 default:break;
		}
		return ch;
	    
	}
	
	public static void Get(int num, int max,int bracket,int decimals)
	{
		Random random =new Random();
		double  a = 0.0,b=0.0,c=0.0,d=0.0;
		int e;
		char op,x,y,z;
		if( bracket==0&& decimals ==0 )
		{
			for (int i = 0;i< num; i++)
			{
				a=random.nextInt(max)+1;
				b=random.nextInt(max)+1;
				c=random.nextInt(max)+1;
				d=random.nextInt(max)+1;
				 for(int j=0;;j++)
			        {
			            if(a<=max&&b<=max&&c<=max&&d<=max)
			            {
			                break;
			            }
			            else {
			            	a=random.nextInt(max)+1;
							b=random.nextInt(max)+1;
							c=random.nextInt(max)+1;
							d=random.nextInt(max)+1;
			            }
			       }
				    op=Operator();
		            x=op;
		            op=Operator();
		            y=op;
		            op=Operator();
		            z=op;
		            System.out.printf("%.0f%c%.0f%c%.0f%c%.0f=\n",a,x,b,y,c,z,d);
		  }
		
	    }
		if (bracket == 0 && decimals == 1)
	    {

	        for (int i = 0; i < num; i++)
			 {
	        	a=random.nextFloat()*max;
				b=random.nextFloat()*max;
				c=random.nextFloat()*max;
				d=random.nextFloat()*max;
			 
	        for(int j=0;;j++)
	        {
	        	if( a<=max&&b<=max&&c<=max&&d<=max)
	            {
	                break;
	            }
	            else
	                {
	            	a=random.nextFloat()*max;
					b=random.nextFloat()*max;
					c=random.nextFloat()*max;
					d=random.nextFloat()*max;
	                }
	        }
	        op=Operator();
            x=op;
            op=Operator();
            y=op;
            op=Operator();
            z=op;
            System.out.printf("%.1f%c%.1f%c%.1f%c%.1f=\n",a,x,b,y,c,z,d);
	        
		}
	    }
		if (bracket == 1 && decimals == 0)
	    {
	        for (int i = 0; i < num; i++)
	        {
	        	a=random.nextFloat()*max;
				b=random.nextFloat()*max;
				c=random.nextFloat()*max;
				d=random.nextFloat()*max;
				e=random.nextInt(100)%4;
				for(int j=0;;j++)
		        {

		            if(a<=max&&b<=max&&c<=max&&d<=max)
		            {

		                break;
		            }
		            else
		                {
		            	a=random.nextFloat()*max;
						b=random.nextFloat()*max;
						c=random.nextFloat()*max;
						d=random.nextFloat()*max;
		                }
		        }
				    op=Operator();
		            x=op;
		            op=Operator();
		            y=op;
		            op=Operator();
		            z=op;
		            if (e == 0)
		            {
		                System.out.printf("(%.0f%c%.0f)%c(%.0f%c%.0f)=\n",a,x,b,y,c,z,d);
		            }
		            if (e == 1)
		            {
		                System.out.printf("%.0f%c(%.0f%c%.0f)%c%.0f=\n",a,x,b,y,c,z,d);
		            }
		            if (e == 2)
		            {
		                System.out.printf("(%.0f%c%.0f%c%.0f)%c%.0f=\n",a,x,b,y,c,z,d);
		            }
		            if (e ==3)
		            {
		                System.out.printf("%.0f%c((%.0f%c%.0f)%c%.0f))=\n",a,x,b,y,c,z,d);		            }
		            
	        }
	    }
		
		if (bracket == 1 && decimals == 1)
	    {
	        for (int i = 0; i < num; i++)
	        {
	        	a=random.nextFloat()*max;
				b=random.nextFloat()*max;
				c=random.nextFloat()*max;
				d=random.nextFloat()*max;
	        	e=random.nextInt(100)%4; 
		     for(int j=0;;j++)
             {
            if(a<=max&&b<=max&&c<=max&&d<=max)
            {
                break;
            }
            else
                {
            	a=random.nextFloat()*max;
				b=random.nextFloat()*max;
				c=random.nextFloat()*max;
				d=random.nextFloat()*max;
                }
             }

            op=Operator();
            x=op;
            op=Operator();
            y=op;
            op=Operator();
            z=op;
            if (e == 0)
            {
                System.out.printf("(%.1f%c%.1f)%c(%.1f%c%.1f)=\n",a,x,b,y,c,z,d);
            }
            if (e == 1)
            {
                System.out.printf("%.1f%c(%.1f%c%.1f)%c%.1f=\n",a,x,b,y,c,z,d);
            }
            if (e == 2)
            {
            	System.out.printf("(%.1f%c%.1f%c%.1f)%c%.1f=\n",a,x,b,y,c,z,d);
            }
            if (e ==3)
            {
                System.out.printf("%.1f%c((%.1f%c%.1f)%c%.1f)=\n",a,x,b,y,c,z,d);
            }
	    }
	    }
	
	}
	public static void main(String[] args)
	{
		
		Scanner scan= new Scanner(System.in);
		System.out.println("请输入出题数目:");
		int num=scan.nextInt();
		System.out.println("题目中数的最大值:");
		int max=scan.nextInt();
		System.out.println("题目中是否需要出现括号？1.想要  0.不想要");
		int bracket=scan.nextInt();
		System.out.println("题目中是否需要出现小数？1.想要  0.不想要");	 
		int decimals=scan.nextInt();
		Get(num,max,bracket,decimals);
		
	}
	
}
	


