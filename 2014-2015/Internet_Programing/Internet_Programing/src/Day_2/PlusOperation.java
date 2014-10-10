package Day_2;

import java.util.ArrayList;

public class PlusOperation implements Operation{
	ArrayList<Integer> list = new ArrayList<Integer>();
	
	public PlusOperation(String [] args) {
		for(int i = 0; i < args.length-1 ;i++){
			list.add(Integer.parseInt(args[i]));
		}
	}
	
	@Override
	public double execute() {
		int result = 0;
		for(int i = 0; i < list.size(); i++){
			result += list.get(i);
		}
		System.out.println(result);
		return result;
	}

}
