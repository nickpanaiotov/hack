<?hh
require_once $_SERVER['DOCUMENT_ROOT'].'/application/models/fakeDb.hh';

abstract class Api extends Controller {

    protected function db_result_main(): string {
  	$ret = '';
  		foreach ((new FakeDB())->getRawRows() as $result) {

			$ret .= sprintf(
      	"id => %u, name => %s, extra => array('msg_adress' => %s)\n",
      	$result['id'],
      	$result['name'],
      	$result['msg_adress'],
    	);
  	    }
  		return $ret;
	}
}
