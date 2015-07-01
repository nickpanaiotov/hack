<?hh

type DBResult = shape(
  'id' => int,
  'name' => string,
  'msg_adress' => string
);

final class FakeDB {
  	public function getRawRows(): array<array<string, mixed>> {

	// Real code would query a DB, but for now let's hardcode it
    return array(
      array(
        'id' => 123,
        'name' => 'Device_123',
        'msg_adress' => '192.168.1.123',
      ),
      array(
        'id' => 456,
        'name' => 'Device_456',
        'msg_adress' => '192.168.1.456',
      ),
    );
	}
}
