#include <Bounce2.h>

#define BUZZ A0
#define MAX_NUM 100

const char LED[5] = { A5, A4, A3, A2, A1 };
const char TONE[5] = { 262, 294, 330, 349, 392 }; // 도 레 미 파 솔

int GAME_SEQUENCE[MAX];
int GAME_STATE;

int current_sequence = 0;
int user_sequence;
unsigned long preTime = 0; // count-Down

Bounce db1 = Bounce();
Bounce db2 = Bounce();
Bounce db3 = Bounce();
Bounce db4 = Bounce();
Bounce db5 = Bounce();

void setup()
{
	// BUZZ
	pinMode( BUZZ, OUTPUT );

	// LED
	for ( int i = 0; i < 5; i++ )
		pinMode( LED[i], OUTPUT );

	// BUTTON
	for ( int i = 2; i < 7; i++ )
		pinMode( i, INPUT_PULLUP );

	// setAttach
	db1.attach( 2 );
	db2.attach( 3 );
	db3.attach( 4 );
	db4.attach( 5 );
	db5.attach( 6 );

	// setInterval
	db1.interval( 5 );
	db2.interval( 5 );
	db3.interval( 5 );
	db4.interval( 5 );
	db5.interval( 5 );

	Serial.begin( 9600 );
}

void loop()
{
	// UPDATE
	db1.update();
	db2.update();
	db3.update();
	db4.update();
	db5.update();

	if ( current_sequence == 1 ) // set 'GAME_SEQUENCE'
	{
		setSequence();
		showSequence();
	}
	else if ( current_sequence == 2 ) // timer
	{
	}
	else if ( current_sequence == 3 ) // user input
	{
		int v[5] = { db1.read(), db2.read(), db3.read(), db4.read(), db5.read() };

		for ( int i = 0; i < 5; i++ )
		{
			if( v[i] == LOW )
			{
				tone( BUZZ, TONE[i], 300 );
				user_sequence = checkSequence( i, user_sequence );

			}
		}
	}
}

void setSequence()
{
	if( current_sequence != 100 )
	{
		int v = analogRead(A15);
		v = v % 5;
		GAME_SEQUENCE[++current_sequence] = v;
	}
}

void showSequence()
{
	for ( int i = 0; i < current_sequence; i++ )
	{
		// SERIAL
		Serial.print( " " );
		Serial.print( GAME_SEQUENCE[i] + 1 );

		// BUZZ
		tone( BUZZ, TONE[ GAME_SEQUENCE[i] ], 300 );

		// LED
		digitalWrite( LED[ GAME_SEQUENCE[i] ], HIGH );
		delay( 300 );
		digitalWrite( LED[ GAME_SEQUENCE[i] ], LOW );

		delay( 600 );
	}
	Serial.println();
}

int checkSequence( int num, int sequence )
{
	Serial.print("SEQUENCE : ");
	Serial.print( current_sequence );
	Serial.print(" SQ : ");
	Serial.print( sequence )	
}