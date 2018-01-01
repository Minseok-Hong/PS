import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		
		Scanner scan = new Scanner(System.in);
		
		int output=0;
		int input = scan.nextInt();
		
		for(int i = 1 ; i <= input ; i++)
		{
			output += i;
		}
		
		System.out.println(output);
	}

}
