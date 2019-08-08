import java.util.Calendar;
import java.util.Scanner;

public class HeartRates {
	private String firstName;
	private String lastName;
	private int birthMonth;
	private int birthDay;
	private int birthYear;
	
	HeartRates(String fName, String lName, int bMonth, int bDay, int bYear){
		firstName = fName;
		lastName = lName;
		birthMonth = bMonth;
		birthDay = bDay;
		birthYear = bYear;
	}
	
	public String get_first_name(){
		return firstName;
	}
	
	public String get_last_name(){
		return lastName;
	}
	
	public int get_birth_month(){
		return birthMonth;
	}
	
	public int get_birth_day(){
		return birthDay;
	}
	
	public int get_birth_year(){
		return birthYear;
	}
	
	public void set_first_name(String fName){
		fName = firstName;
	}
	
	public void set_last_name(String lName){
		lName = lastName;
	}
	
	public void set_birth_month(int month){
		birthMonth = month;
	}
	
	public void set_birth_day(int day){
		birthDay = day;
	}
	
	public void set_birth_year(int year){
		birthYear = year;
	}
	
	public int get_age(){
		 Calendar calendar = Calendar.getInstance();
		 
		 if (birthMonth < calendar.get(Calendar.MONTH) + 1){
			 return calendar.get(Calendar.YEAR) - birthYear;
		 }
		 else if(birthMonth > calendar.get(Calendar.MONTH) + 1){
			 return calendar.get(Calendar.YEAR) - birthYear - 1;
		 }
		 else{
			 if(birthDay <= calendar.get(Calendar.DAY_OF_MONTH)){
				 return calendar.get(Calendar.YEAR) - birthYear; 
			 }
			 else if (birthDay > calendar.get(Calendar.DAY_OF_MONTH)){
				 return calendar.get(Calendar.YEAR) - birthYear - 1; 
			 }
		 }
		 return 0;
	}
	
	public int max_heart_rate(){
		return 220 - get_age();
	}
	
	public void target_heart_rate(){
		System.out.println("Heart Rate target is from : " + .5 * max_heart_rate() 
															+ " to " + .85 * max_heart_rate());
	}


	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		System.out.println("What is your first name? ");
		String fName = input.nextLine();
		System.out.println("What is your last name? ");
		String lName = input.nextLine();
		System.out.println("What is your birth month? ");
		int bMonth = input.nextInt();
		System.out.println("What is your birth day? ");
		int bDay = input.nextInt();
		System.out.println("What is your birth year? ");
		int bYear = input.nextInt();
		
		Calendar dob = Calendar.getInstance();
		dob.set(bYear, bMonth-1, bDay);
		Calendar current = Calendar.getInstance();
		
		boolean correctDays = bDay <= dob.get(Calendar.DAY_OF_MONTH) && bDay > 0;
		boolean correctMonths = bMonth < 13 && bMonth > 0;
		boolean correctYears = bYear <= current.get(Calendar.YEAR);
		
		if(correctDays && correctMonths && correctYears){
			HeartRates user = new HeartRates(fName, lName, bMonth, bDay, bYear);
			System.out.println("First Name : " + user.get_first_name());
			System.out.println("Last Name : " + user.get_last_name());
			System.out.println("Date of Birth : " + bMonth + "/" + bDay + "/" + bYear);
			System.out.println("Age : " + user.get_age());
			System.out.println("Maxmimum Heart Rate : " + user.max_heart_rate());
			user.target_heart_rate();
		}
		else{
			System.out.println("Do you not know your own birthday? Because it doesn't exist.");
		}
		
	
	}
}
