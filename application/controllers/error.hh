<?hh // strict

class Error extends Controller {

	public function index(): void {
		$this->error404();
	}

	public function error404(): void {
		echo '<h1>404 Error</h1>';
		echo '<p>Looks like this page doesn\'t exist</p>';
	}

}
