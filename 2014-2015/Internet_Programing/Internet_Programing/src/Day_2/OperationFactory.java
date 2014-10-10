package Day_2;

public class OperationFactory {
	
	String operation = "";
	String [] args;
	
	public OperationFactory(String [] args){
		operation = args[args.length - 1];
		this.args = args;
	}
	
	public Operation create(){
		switch(operation){
		case "+":
			return new PlusOperation(args);
		case "-":
			return new MinusOperation(args);
		case "*":
			return new MultiplyOperation(args);
		case "/":
			break;
		}
		return null;
	}
	
}
