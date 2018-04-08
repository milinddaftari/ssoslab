import java.util.Scanner;

public class calc
{
	public static void main(String args[])
	{
		double a,b,res;
		int ch;
		Scanner in = new Scanner(System.in);
			System.out.println("\nEnter a ");
			a = in.nextDouble();
			System.out.println("\nEnter b ");
			b = in.nextDouble();
			System.out.println("--Choose Operation--");
			System.out.println("\n1.Addition \n2.Subtraction \n3.Multiplication \n4.Division\n");
			ch = in.nextInt();
			switch(ch)
			{
				case 1 :  res = a+b;
							System.out.println(a + "+" + b + "=" + res);
							break;
				case 2 :  res = a-b;
							System.out.println(a + "-" + b  + "=" + res);
							break;
				case 3 :  res = a*b;
							System.out.println(a + "*" + b + "=" + res);
							break;
				case 4 :  if(b!=0)
							{
								res = a/b;
								System.out.println(a + "/" + b + "=" + res);
								break;
							}
							else
							{
								System.out.println("--Invalid--");
							}
			}
	}
}