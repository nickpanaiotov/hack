<?hh

class hack_mvc {


    public function __construct(): void {

        // Set our defaults
        $controller = cDefaultController;
        $action = 'index';
        $url = '';

        // Get request url and script url
        $request_url = (isset($_SERVER['REQUEST_URI'])) ? $_SERVER['REQUEST_URI'] : '';
        $script_url  = (isset($_SERVER['PHP_SELF'])) ? $_SERVER['PHP_SELF'] : '';

        // Get our url path and trim the / of the left and the right
        if($request_url != $script_url) $url = trim(preg_replace('/'. str_replace('/', '\/', str_replace('index.hh', '', $script_url)) .'/', '', $request_url, 1), '/');

        // Split the url into segments
        $segments = explode('/', $url);

        // Do our default checks
        if(isset($segments[0]) && $segments[0] != '') $controller = $segments[0];
        if(isset($segments[1]) && $segments[1] != '') $action = $segments[1];

        // Get our controller file
        $path = APP_DIR . 'controllers/' . $controller . '.hh';
        if(file_exists($path)){
            include_once($path);
        } else {
            $controller = cErrorController;
            include_once(APP_DIR . 'controllers/' . $controller . '.hh');
        }

        // Check the action exists
        if(!method_exists($controller, $action)){
            $controller = cErrorController;
            include_once(APP_DIR . 'controllers/' . $controller . '.hh');
            $action = 'index';
        }

        // Create object and call method
        $obj = new $controller();
        die(call_user_func_array(array($obj, $action), array_slice($segments, 2)));
    }
}

/*
// in a .hhi file that starts with <?hh // decl
function parse_ini_file(string, bool);
*/
