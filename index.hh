<?hh
/* @flow */
//Start the Session
session_start();

// Defines
define('ROOT_DIR', realpath(dirname(__FILE__)).'/');
define('APP_DIR', ROOT_DIR.'application/');

require (APP_DIR.'config/config.hh');

// Define base URL
define('BASE_URL', cBaseURL);

// Includes
require (ROOT_DIR.'system/model.hh');
require (ROOT_DIR.'system/controller.hh');
require (APP_DIR.'controllers/api.hh');
require (ROOT_DIR.'system/hack_mvc.hh');


new hack_mvc();
