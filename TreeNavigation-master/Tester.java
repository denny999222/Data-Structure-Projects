package Assignment2;
import Assignment2.BinomialTreeFactory;
import java.util.Scanner;

public class Tester {

	public static void main(String args[]){
		
		/*System.out.println("How many levels do you want for the tree? ");
		Scanner input = new Scanner(System.in);
		int times = input.nextInt();
		
		System.out.println("What probability of going up do you want? ");
		int probUp = input.nextInt();
		
		
		buildTree(times, probUp, root);
		
		System.out.println("How many levels do you want to navigate? ");
		int levels = input.nextInt();

		navigate(levels);*/
		Scanner input = new Scanner(System.in);
		System.out.println("How many levels do you want for the tree? ");
		int time = input.nextInt();
		System.out.println("What probability of going up do you want? ");
		int prob = input.nextInt();
		System.out.println("How many levels do you want to navigate? ");
		int itera = input.nextInt();
		TreeNode root = new TreeNode(0,prob,null,null);
		BinomialTreeFactory.buildTree(time,prob,root);
		Navigator nav = new Navigator(itera);
		System.out.println(root.time);
		nav.navigate(root, itera);
		input.close();
	}
	
}
