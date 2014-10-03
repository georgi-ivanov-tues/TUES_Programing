package Day_1;

import javax.script.ScriptException;

public class Main {
	public static void main(String[] args) throws ScriptException {
//		final int a = 15;
//		System.out.println(Integer.parseInt(args[0]) + Integer.parseInt(args[1]) >= a ? 
//				"Po-golqmo\n" : "Po-malko\n");
//		
//		int num = Integer.parseInt(args[0]) / Integer.parseInt(args[1]);
//		double num2 = Double.parseDouble(args[0]) / Double.parseDouble(args[1]);
//		System.out.println(num + "\n" + num2 + "\n");
//		
//		double covert = 3.78541178;
//		for(int i = 0; i < args.length; i++){
//			System.out.println(Integer.parseInt(args[i]) * covert);
//		}
//		
		
		int answer = Integer.parseInt(args[0]);
		for(int i = 1; i < args.length - 1; i++){
			switch(args[args.length - 1]){
			case "+":
				answer = answer + Integer.parseInt(args[i]);
				break;
			case "-":
				answer = answer - Integer.parseInt(args[i]);
				break;
			case "*":
				answer = answer * Integer.parseInt(args[i]);
				break;
			case "/":
				answer = answer / Integer.parseInt(args[i]);
				break;
			}
		}
		System.out.println(answer);
		
		/*
		// Javascript Engine answer
		
		char operator = args[args.length - 1].charAt(0);
		ScriptEngineManager scm = new ScriptEngineManager();
		ScriptEngine jsEngine = scm.getEngineByName("JavaScript");
		Integer result = (Integer) jsEngine.eval(args[0] + operator + args[1]);
		System.out.println(result);
		*/
	}
}

/* 
Nenko Tabakov
email: nenko.tabakov@gmail.com

Domashno
1.
Statistika: 
Kak razli4ni eizici se spravqt s razli4ni problemi i re6avaniqta im

2.
Razlika mejdu static v C++ i Java

3.
Polimorfizam, enkapsolaciq, nasledqvane na obekti
*/