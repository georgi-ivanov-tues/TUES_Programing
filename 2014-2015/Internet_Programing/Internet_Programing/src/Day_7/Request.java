package Day_7;

import java.util.Map;

public class Request {
	private String method;
	private String resource;
	private String version;
	private Object body;
	private Map<String,String> headers;
	
	public Request(String method, String resource, String version, Object body, Map<String,String> headers){
		this.method = method;
		this.resource = resource;
		this.version = version;
		this.body = body;
		this.headers = headers;
	}
	
	public String getMethod() {
		return method;
	}

	public String getResource() {
		return resource;
	}

	public String getVersion() {
		return version;
	}

	public Object getBody() {
		return body;
	}

	public Map<String, String> getHeaders() {
		return headers;
	}
}
