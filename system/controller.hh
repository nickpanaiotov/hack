<?hh

class Controller {

	public function loadModel(string $name): Model {
		include(APP_DIR .'models/'. strtolower($name) .'.php');

		$model = new $name();
		return $model;
	}

	public function loadPlugin(string $name): void {
		include(APP_DIR .'plugins/'. strtolower($name) .'.php');
	}

	public function loadHelper(string $name): mixed /* @todo Something, maybe Helper interface */ {
		include(APP_DIR .'helpers/'. strtolower($name) .'.php');
		$helper = new $name();
		return $helper;
	}

	public function redirect(string $loc): void {
		header('Location: '. cBaseURL . $loc);
        exit;
	}

}
