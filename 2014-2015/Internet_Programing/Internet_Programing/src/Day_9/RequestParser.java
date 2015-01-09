package Day_9;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class RequestParser {

	public Request parse(List<String> request) {
		String[] firstLineParsed = request.remove(0).split(" ");

		Map<String, String> headers = new HashMap<>();
		for (String header : request) {
			String[] secondLine = header.split(": ");
			headers.put(secondLine[0], secondLine[1]);
		}
		
		List<String> bodyList = new ArrayList<String>();

		for(String asd : request){
			boolean isBody = false;
			if(asd.equals("/r/n/r/n")){
				isBody = true;
				continue;
			}
			
			if(isBody){
				System.out.println("BODY = " + asd);
				bodyList.add(asd);
			}
		}
		
		Object body = bodyList;
		
		parsePathParams(firstLineParsed[1]);
		
		return new Request(firstLineParsed[0],
				firstLineParsed[1], firstLineParsed[2], body, headers);
	}
	
	public void parsePathParams(String path){
		String[] afterArray = path.split("/");
		String after = afterArray[afterArray.length - 1];
		String[] query = after.split("\\?");

		if(query.length == 1){
			return;
		}
		
		String[] queryParams = query[1].split("&");
		
		Set<String> set = new HashSet<String>();
		set.add(queryParams[0]);
		
		Map<String, String> map = new LinkedHashMap<String, String>();
		for(int i = 0; i < queryParams.length; i++){
			String[] valio = queryParams[i].split("=");
			map.put(valio[0], valio[1]);
		}
		
		for (Entry<String, String> v : map.entrySet()) {
			System.out.println(v.getKey() + " = " + v.getValue());
		}
		
	}
}