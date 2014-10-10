package Day_2;

import java.util.ArrayList;

public class MinusOperation implements Operation{
	ArrayList<Integer> list = new ArrayList<Integer>();
	
	public MinusOperation(String [] args) {
		for(int i = 0; i < args.length-1 ;i++){
			list.add(Integer.parseInt(args[i]));
		}
	}
	
	@Override
	public double execute() {
		int result = list.get(0);
		for(int i = 1; i < list.size(); i++){
			result -= list.get(i);
		}
		System.out.println(result);
		return result;
	}
	
}
