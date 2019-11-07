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
		
		Pattern p = Pattern.compile("^[a-zA-Z]{1,20}$");
		Matcher m = p.matcher(fName);
		
		System.out.println(m.matches());
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 20 upper or lower case alphabetic characters for first name");
			fName = kIn.nextLine();
		}
		
		System.out.println("Input Last Name with length of at most 30 characters and comprised of only upper or lower case alphabetic characters");
		lName = kIn.nextLine();
		
		p = Pattern.compile("^[a-zA-Z]{1,30}$");
		Matcher m = p.matcher(fName);
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 30 upper or lower case alphabetic characters for last name");
			lName = kIn.nextLine();
		}
		
	}
	
	private static void readInts()
	{
		
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
			
			File inFile = new File(kIn.hasNextLine());
		}
		
		return inFile;
		
	}
	
	private static void getOutputFile()
	{
		
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
