package defendCode;

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
		
		System.out.println("Input First Name with length of at most 20 characters");
		fName = kIn.nextLine();
		
		while(fName.length() > 20)
		{
			System.out.println("Input was too long. Reenter first name with at most 20 characters");
			fName = kIn.nextLine();
		}
		
		System.out.println("Input Last Name with length of at most 20 characters");
		lName = kIn.nextLine();
		
		while(lName.length() > 30)
		{
			System.out.println("Input was too long. Reenter first name with at most 20 characters");
			lName = kIn.nextLine();
		}
		
		//Here we should do some RegEx to make sure names are formatted right
	}
	
	private static void readInts()
	{
		
	}
	
	private static void getInputFile()
	{
		
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
