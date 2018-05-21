import java.util.*;

class pagerep
{
	public static int page_seq[],frame[],frame_size,ref_len;
	public static int i,j,k;

	public static int min(int a[])
	{
		int min=0;
		min = a[0];
		for(j=0;j<a.length;j++)
			if(a[j]<=min)
				min = a[j];
		return min;
	}

	public static int getIndex(int i)
	{
		int index = 0;
		int ind[] = new int[frame_size];
		for(k=0;k<frame_size;k++)
			for(j=i-1;j>=0;j--)
				if(frame[k]==page_seq[j])
				{
					ind[k] = j;
					break;
				}
		index = min(ind);
		for(k=0;k<frame_size;k++)
			if(frame[k]==page_seq[min(ind)])
			{
				index = k;
				break;
			}
		return index;
	}

	public static void LRU()
	{
		int pf=0,ind=0,d=1;
		for(k=0;k<frame_size;k++)
			frame[k]=999;
		for(i=0;i<ref_len;i++)
			{
				if(i<frame_size)
				{
					frame[i] = page_seq[i];
					System.out.println("Page" + page_seq[i] + " : ");
					pf++;
				}
				else
				{
					System.out.print("Page" + page_seq[i] + " : ");
					for(j=0;j<frame_size;j++)
					{
						if(page_seq[i]==frame[j])
						{
							d=0;
							break;
						}
					}
					if(d==0)
					{
						d=1;
						System.out.println(" ");
						continue;
					}
					else
					{
						ind = getIndex(i);
						frame[ind] = page_seq[i];
						pf++;
					}
				}
				for(int x : frame)
					System.out.println(x + "\t");
			}
			System.out.println("Page Faults = " + pf);
	}

	public static void FIFO()
	{
		int pf=0,d=1,index=0;
		for(k=0;k<frame_size;k++)
			frame[k]=999;
		for(i=0;i<ref_len;i++)
		{
			System.out.print("Page" + page_seq[i] + " : ");
			for(j=0;j<frame_size;j++)
				if(page_seq[i]==frame[j])
				{
					d=0;
					break;
				}
			if(d==0)
			{
				d=1;
				System.out.println(" ");
				continue;
			}
			else
			{
				frame[index] = page_seq[i];
				index = (index+1)%frame_size;
				pf++;
			}
			for(int x : frame)
				System.out.println(x + "\t");
			System.out.println(" ");
		}
		System.out.println("Page Faults = " + pf);
	}

	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number of frames ");
		frame_size = in.nextInt();
		System.out.println("Enter the length of reference string ");
		ref_len = in.nextInt();
		page_seq = new int[ref_len];
		frame = new int[frame_size];
		System.out.println("Enter the reference string ");
		for(k=0;k<ref_len;k++)
			page_seq[k] = in.nextInt();
		while(true)
		{
			System.out.println("Enter your choice ");
			System.out.println("1.FIFO ");	
			System.out.println("2.LRU ");
			System.out.println("3.EXIT ");
			switch(in.nextInt())
			{
				case 1 : FIFO();
						 break;
				case 2 : LRU();
						 break;
				case 3 : System.exit(0);
			}	
		}		

	}

}