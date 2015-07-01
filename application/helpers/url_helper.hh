<?hh // strict

class Url_helper {

	public function base_url(): string {
		return cBaseURL;
	}
	
	public function segment(mixed $seg): bool {
		if(!is_int($seg)) return false;
		
		$parts = explode('/', $_SERVER['REQUEST_URI']);
	    return isset($parts[$seg]) ? $parts[$seg] : false;
	}
	
}