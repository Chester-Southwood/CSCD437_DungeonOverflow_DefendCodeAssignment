package defendCode;

import java.io.File;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DefendCode {

	
	public static void main(String[] args)
	{
		String fName = "";
		String lName = "";
		
		readName(fName, lName);
		
	}
	
	private static void readName(String fName, String lName)
	{
		Scanner kIn = new Scanner(System.in);
		
		System.out.println("Input First Name with length of at most 20 characters and comprised of only upper or lower case alphabetic characters");
		fName = kIn.nextLine();
		
		Pattern p = Pattern.compile("^[a-zA-Z]{1,50}$");
		Matcher m = p.matcher(fName);
		
		System.out.println(m.matches());
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 50 upper or lower case alphabetic characters for first name");
			fName = kIn.nextLine();
		}
		
		System.out.println("Input Last Name with length of at most 50 characters and comprised of only upper or lower case alphabetic characters");
		lName = kIn.nextLine();
		
		p = Pattern.compile("^[a-zA-Z]{1,50}$");
		Matcher m = p.matcher(fName);
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 50 upper or lower case alphabetic characters for last name");
			lName = kIn.nextLine();
		}
		
	}
	
	/*
	 * Generic method used for getting valid int from user via passed in Scanner
	 * and message for looping for prompt until a valid range for a int is entered
	 * and then returned.
	 * 
	 * @param userScanner Scanner(System.in) for user input from terminal.
	 * @param numMessage  String message to make method generic if needed.
	 * 
	 * @return     		  Int value that is in a valid range without overflow/underflow.
	 */
	public static int readInts(final Scanner userScanner, final String numMessage)
	{		
		boolean gotNum   = false;
		int     numValue = -1;
		
		while(!gotNum)
		{
			System.out.println(numMessage);
			try
			{
				numValue = userScanner.nextInt();
				gotNum   = true;
			}
			catch(NumberFormatException e) //exception thrown if outOfRange or outOfFormat
			{
				System.out.println("Incorrect input!");
				System.out.println(numMessage);
			}
			finally
			{
				userScanner.nextLine(); //clear buffer
			}
		}
		
		return numValue;
	}
   
   	/*
	 * Takes two int values and determines if the product is a valid int.
	 * As long as the product is in range of int, it doesn't matter to keep
	 * track of the sign change.
	 * 
	 * @param num1 Integer value used to determine product.
	 * @param num2 Integer value used to determine product.
	 * 
	 * @return     Boolean value that tells if int product is possible with the
	 * 			   two passed int values.
	 */
	public static boolean canMultiply(final int num1, final int num2)
	{
		boolean canAdd = true;
		int     sum    = 0;
		
		int num1Copy   = num1;
		int num2Copy   = num2;
		
		for(int i = 0; i < Math.abs(num1) && canAdd; i++)
		{
			if(canAdd(sum, num2Copy))
			{
				sum = num2Copy + sum;
			}
			else
			{
				canAdd = false;
			}
		}
		
		return canAdd;
	}
	
	/*
	 * Takes two int values and determines if the sum is a valid int.
	 * A sum is determined if it's in range of Integer.MIN_VALUE and INTEGER.MAX_VALUE.
	 * 
	 * @param num1 Integer value used to determine if valid int sum.
	 * @param num2 Integer value used to determine if valid int sum.
	 * 
	 * @return     Boolean value that tells if int sum is possible with the
	 * 			   two passed int values.
	 */
	public static boolean canAdd(final int num1, final int num2)
	{
		final long longNum1 = (long) num1;
		final long longNum2 = (long) num2;
		
		final long longSum  = longNum1 + longNum2;
		
		return Integer.MIN_VALUE <= longSum && longSum <= Integer.MAX_VALUE;
	}
	
	private static file getInputFile()
	{
		Scanner kIn = new Scanner(System.in);
		System.out.println("Input the input file name. Only alphabetic characters may be used. Only .txt files may be used. File must exist in same directory the program is in.");
		
		File inFile = new File(kIn.hasNextLine());
		Pattern pat = Pattern.compile("^\\w+.txt$");
		Matcher m = pat.matcher(inFile.getPath());
		
		while(!inFile.exists() && !m.matches())
		{
			System.out.println("File does not exist. Re-enter with a existing file. If no file exists please create one.");
			
			//Do RegEx to check for valid file path?
			
			inFile = new File(kIn.hasNextLine());
		}
		
		return inFile;
		
	}
	
	private static file getOutputFile()
	{
		Scanner kIn = new Scanner(System.in);
		System.out.println("Input the output file name. Only alphabetic characters may be used. Only .txt files may be used. File must exist in same directory the program is in.");
		
		File outFile = new File(kIn.hasNextLine());
		Pattern pat = Pattern.compile("^\\w+.txt$");
		Matcher m = pat.matcher(outFile.getPath());
		
		while(!outFile.exists() && !m.matches())
		{
			System.out.println("File does not exist. Re-enter with a existing file. If no file exists please create one.");
			
			//Do RegEx to check for valid file path?
			
			outFile = new File(kIn.hasNextLine());
		}
		
		return outFile;
	}
	
	private static void passWord()
	{
		Scanner kIn = new Scanner(System.in);
		System.out.println("Enter Password, must be at least 1 character in length");
		
		String pw = kIn.nextLine();
		
		while(!(pw.length() >= 1))
		{
			System.out.println("Password too short, please reenter.");
			pw = kIn.nextLine();
		}
		
		System.out.println("Reenter Password to validate match.");
		String pw2 = kIn.nextLine();
		
		while(!pw.equals(pw2))
		{
			System.out.println("Reenter Password to validate match.");
			pw2 = kIn.nextLine();
		}
		
		System.out.println("Password Valid, have a good day.");
	}
	
	private static void writeName()
	{
		
	}
	
	private static void writeSum()
	{
		
	}
	
	private static void writeContents()
	{
		
	}
}
