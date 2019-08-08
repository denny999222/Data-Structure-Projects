package Assignment2;

public class TreeNode {
	
	public int time;
	public TreeNode up_child;
	public TreeNode down_child;
	public final int probability;
	
	public TreeNode (int t, int prob, TreeNode up, TreeNode down){
		time = t;
		up_child = up;
		down_child = down;
		probability = prob;
	} 
	
	public void add_both_nodes(){
		down_child = new TreeNode(time + 1, probability, null, null);
		up_child = new TreeNode(time + 1, probability, null, null);
	}
}
