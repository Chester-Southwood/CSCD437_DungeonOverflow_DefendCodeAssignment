import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

public class DefendCode{
	private static FileWriter fw = null;
	private static String fName = "";
	private static String lName = "";
	private static int num1 = 0;
	private static int num2 = 0;
	private static File inputFile = null;
	private static final String END = "\r\n";
	
	public static void main(String[] args) throws Exception
	{
		

		
		
		createWriter(false);
		inputFile = getInputFile();

		readName();
		Scanner sc = new Scanner(System.in);
		num1 = readInts(sc, "Please enter the 1st number.");
		num2 = readInts(sc, "Please enter the 2nd number.");
		getPassword();
		System.out.println("Please enter a password.");
		while (!comparePassword())
		{
			System.out.println("Invalid. Please enter the password again.");
		}
		
		writeAll(fName, lName, num1, num2, inputFile);
		
	}
	
	private static void readName()
	{
		Scanner kIn = new Scanner(System.in);
		
		System.out.println("Input First Name with length of at most 50 characters and comprised of only upper or lower case alphabetic characters");
		fName = kIn.nextLine();
		
		Pattern p = Pattern.compile("^[a-zA-Z]{1,50}$");
		Matcher m = p.matcher(fName);
		
		//System.out.println(m.matches());
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 50 upper or lower case alphabetic characters for first name");
			fName = kIn.nextLine();
			m = p.matcher(fName);
		}
		
		System.out.println("Input Last Name with length of at most 50 characters and comprised of only upper or lower case alphabetic characters");
		lName = kIn.nextLine();
		
		p = Pattern.compile("^[a-zA-Z]{1,50}$");
		m = p.matcher(lName);
		
		while(!m.matches())
		{
			System.out.println("Input was invalid. You must have between 1 and 50 upper or lower case alphabetic characters for last name");
			lName = kIn.nextLine();
			m = p.matcher(lName);
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
	public static int readInts(final Scanner userScanner, final String numMessage) throws Exception
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
				System.out.println("Number Format Exception. Error message written to output file specified.");
				System.out.println(numMessage);
				FileWriter fWriter = getWriter();
				fWriter.append(e.getMessage());
				fWriter.flush();
			}
			catch(InputMismatchException e) //Exception thrown if number is larger or smaller than MAX_INT or MIN_INT
			{
				System.out.println("Input Mismatch Exception. Error message written to output file specified.");
				FileWriter fWriter = getWriter();
				fWriter.append(e.getMessage());
				fWriter.flush();
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
	
	private static File getInputFile()
	{
		Scanner kIn = new Scanner(System.in);
		System.out.println("Input the input file name. Only alphabetic characters may be used. Only .txt files may be used. File must exist in same directory the program is in.");
		
		File inFile = new File(kIn.nextLine());
		Pattern pat = Pattern.compile("^\\w+.txt$");
		Matcher m = pat.matcher(inFile.getPath());
		
		while(!inFile.exists() || !m.matches())
		{
			System.out.println("File does not exist. Re-enter with a existing file. If no file exists please create one.");
			
			//Do RegEx to check for valid file path?
			
			inFile = new File(kIn.nextLine());
			m = pat.matcher(inFile.getPath());
		}
		
		return inFile;
		
	}
	
	private static File getOutputFile()
	{
		Scanner kIn = new Scanner(System.in);
		System.out.println("Input the output file name. Only alphabetic characters may be used. Only .txt files may be used. File must exist in same directory the program is in.");
		
		File outFile = new File(kIn.nextLine());
		Pattern pat = Pattern.compile("^\\w+.txt$");
		Matcher m = pat.matcher(outFile.getPath());
		
		while(!outFile.exists() || !m.matches())
		{
			System.out.println("File does not exist. Re-enter with a existing file. If no file exists please create one.");
			
			//Do RegEx to check for valid file path?
			
			outFile = new File(kIn.nextLine());
			m = pat.matcher(outFile.getPath());
		}
		
		return outFile;
	}
	
	private static void getPassword() throws NoSuchAlgorithmException //TODO: Hash, Salt, Stores password
, IOException
	{
		String pwReq = "contains 10 characters, includes at least one upper case character, one lower case, one digit, one punctiation mark and "
		+ " does not have more than 3 consecutive lower case characters.";
		Scanner kIn = new Scanner(System.in);
		System.out.println("Enter a password that: " + pwReq);
		
		String testPW = kIn.nextLine();
		
		Pattern p = Pattern.compile("^(?=.{10,})(?=.*[a-z])(?=.*[A-Z])(?=.*(\"|'|,|\\.|\\!|\\?|\\|\\-|\\:|\\;|<|>|\\{|\\}|\\[|\\]|\\(|\\)/))(?=.*\\d+)(?!.*[a-z]{3}).+");
		Matcher m = p.matcher(testPW);

		//while(testPW.length() < 8)
		while(!m.matches())
		{
			System.out.println("Password was insufficent. Please enter a password that: " + pwReq);
			testPW = kIn.nextLine();
			m = p.matcher(testPW);
		}
		
		SecureRandom sr = SecureRandom.getInstance("SHA1PRNG");
		byte[] salt = new byte[32];
	    sr.nextBytes(salt);
		
		String s = "";
		MessageDigest md = MessageDigest.getInstance("SHA-512");
		
		md.update(salt);
		
		byte[] test = md.digest(testPW.getBytes());
		/*
		for(int ix = 0; ix < test.length; ix++)
		{
			System.out.print(test[ix] +" ");
		}s
		*/
		
        for(int ix = 0; ix < test.length; ix++)
        {
        	
        	//System.out.print(Integer.toString((test[ix] & 0xff) + 0x100, 16) + " -> ");
            s += Integer.toString((test[ix] & 0xff) + 0x100, 16).substring(1);
            //System.out.println(s);
        }
		
        File pFile = new File("pwFile.txt");
        
        if (!pFile.exists())
        {
        	pFile.createNewFile();
        }
        
		FileWriter fw = new FileWriter(pFile);
			
		fw.append("Hash:" + s + "\r\n");
		fw.append("Salt:");
			
		for(int ix = 0; ix < salt.length; ix++)
		{
			fw.append(Integer.toString(salt[ix]) + " ");
		}
			
		fw.flush();
			
		//System.out.println("HIT");
		fw.close();
			

    
	}
	
	private static boolean comparePassword() throws IOException, NoSuchAlgorithmException
	{
		File pFile = new File("pwFile.txt");
		
		if(!pFile.exists())
		{
			pFile.createNewFile();
		}
		
		Scanner pwIn = new Scanner(pFile);
    	
    	String cHash = pwIn.nextLine().substring(5);
    	byte[] cSalt = new byte[32];
    		
    	String saltString = pwIn.nextLine().substring(5);
    		
    	Scanner scn = new Scanner(saltString);
    	//System.out.println(saltString);
    	for(int ix = 0; ix < cSalt.length; ix++)
    	{
    		cSalt[ix] = Byte.parseByte(scn.next());
    	}
    	
    	scn.close();
    	
    	Scanner kIn = new Scanner(System.in);
        String p2 = kIn.nextLine();
		String s2 = "";
        MessageDigest md2 = MessageDigest.getInstance("SHA-512");
		
        md2.update(cSalt);
        byte[] test2 = md2.digest(p2.getBytes());

        for(int ix = 0; ix < test2.length; ix++)
        {
        	
        	//System.out.print(Integer.toString((test[ix] & 0xff) + 0x100, 16) + " -> ");
            s2 += Integer.toString((test2[ix] & 0xff) + 0x100, 16).substring(1);
            //System.out.println(s);
        }
		
        /*
        System.out.println(s2);
        System.out.println(s);
        System.out.println(cHash);
        */
        
        if(s2.compareTo(cHash) == 0)
        {
        	return true;
        }
        else
        {
        	return false;
        }
 
 
	}

	private static void createWriter(File file) throws Exception
	{
		if(fw == null)
		{
			fw = new FileWriter(file);
		}

	}

	private static void createWriter() throws Exception
	{
		if(fw == null)
		{
			fw = new FileWriter(getOutputFile());
		}
	}

	private static void createWriter(File file, boolean append) throws Exception
	{
		fw = new FileWriter(file, append);
	}

	private static void createWriter(boolean append) throws Exception
	{
		if(fw == null)
		{
			fw = new FileWriter(getOutputFile(), append);
		}
	}

	private static void clearFile(File file) throws Exception
	{
		createWriter(file, false);
		System.out.println("File cleared.");
	}

	private static FileWriter getWriter() throws Exception
	{
		if(fw == null) throw new Exception("FileWriter not initialized. Please use createWriter(file) first.");
		return fw;
	}

	private static void closeWriter() throws Exception
	{
		if(fw == null) throw new Exception("Cannot close a null object. Please use createWriter(file) first.");
		fw.close();
	}

	private static void writeName(String fname, String lname) throws Exception
	{
		FileWriter fileWriter = getWriter();
		fileWriter.append(fname + " " + lname + END);
		fileWriter.flush();
	}
	
	private static void writeSum(int num1, int num2) throws Exception
	{
		FileWriter fileWriter = getWriter();
		if(canAdd(num1, num2))
		{
			int sum = num1 + num2;
			fileWriter.append(sum + END);
			fileWriter.flush();
		}
		else
		{
			fileWriter.append("Can't add " + num1 + " and " + num2 + " without causing integer overflow.");
			fileWriter.flush();
		}
	}

	private static void writeProduct(int num1, int num2) throws Exception
	{
		FileWriter fileWriter = getWriter();
		if(canMultiply(num1, num2))
		{
			int product = num1 * num2;
			fileWriter.append(product + END);
			fileWriter.flush();
		}
		else
		{
			fileWriter.append("Can't multiply " + num1 + " and " + num2 + " without causing integer overflow.");
			fileWriter.flush();
		}
	}

	private static void writePassword(String password) throws Exception
	{
		if(password.length() > 0)
		{
			FileWriter fileWriter = getWriter();
			fileWriter.append(password + END);
			fileWriter.flush();
		}

	}
	
	private static void writeContents(File input) throws FileNotFoundException, Exception
	{
		FileWriter fileWriter = getWriter();
		Scanner sc = new Scanner(input);
		while(sc.hasNextLine())
		{
			String line = sc.nextLine();
			fileWriter.append(line + END);
			fileWriter.flush();
		}
	}

	private static void writeAll(String fname, String lname, int num1, int num2, File input) throws Exception
	{
		writeName(fname, lname);
		writeSum(num1, num2);
		writeProduct(num1, num2);
		writeContents(input);
	}
}
