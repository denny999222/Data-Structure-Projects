package Assignment2;


public final class BinomialTreeFactory {
	
	//public static TreeNode cursor = root;
	public static int probability;
	
	public static void buildTree(int T, int P, TreeNode root){
		probability = P;
		if(T>0){
			root.add_both_nodes();
			buildTree(T-1,P,root.up_child);
			buildTree(T-1,P,root.down_child);
			
		}
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	
	
	
	

}
