package Assignment2;

import java.util.Random;

public class Navigator {
	
	public int iter;
	
	public Navigator(int iterations){
		iter = iterations;
	}
	
	
	public void navigate(TreeNode root, int N){
		
		int count = 2;
		Random rand = new Random();
		int prob = rand.nextInt(101);
		
		System.out.println("Step 1");
		System.out.println("Time: "+root.time+" | "+
							"Random Numb Generated : "+prob+" | "+
							"Direction : "+ "ROOT");
		
		while(N > 0){
			prob = rand.nextInt(101);
			if(prob <= BinomialTreeFactory.probability){
				root = root.up_child;
				System.out.println("Step "+ count);
				System.out.println("Time: "+ root.time + "|"+
									"Random Numb Generated :"+prob+ " | "+
									"Direction: "+ "UP");
				count++;
			}
			else{
				root = root.down_child;
				System.out.println("Step "+ count);
				System.out.println("Time: "+ root.time + "| "+
									"Random Numb Generated: "+ prob +" | "+
									"Direction: "+ "DOWN");
				count++;
			}
			
			N--;
		}
		
	}

}
