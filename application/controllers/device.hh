<?hh

class Device extends Api{

    public function getAll()
    {
        $result = $this->db_result_main();
        return $result;
    }
}
