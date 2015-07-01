<?hh

class Session_helper {

	public function set(string $key, mixed $val): void {
		$_SESSION["$key"] = $val;
	}
	
	public function get(string $key): mixed {
		return $_SESSION["$key"];
	}
	
	public function destroy(): void {
		session_destroy();
	}

}