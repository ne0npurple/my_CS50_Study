-- 1. get data from table crime_scene_reports
SELECT * FROM crime_scene_reports WHERE year=2021 AND month=7 AND day=28 AND street="Humphrey Street";
    -- 295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- 2. get the interview data from table interviews.
SELECT * FROM interviews WHERE year=2021 AND month=7 AND day=28 AND transcript LIKE "%Bakery%";
    -- 161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
    -- 162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
    -- 163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- 3. Get the data from parking lot (table bakery_security_logs) ---> BASED ON RUTH'S INFORMATIONS:
    -- 161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
SELECT * FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute>=15 AND minute<=25 AND activity="exit" ORDER BY minute ASC;
    -- 260|2021|7|28|10|16|exit|5P2BI95
    -- 261|2021|7|28|10|18|exit|94KL13X
    -- 262|2021|7|28|10|18|exit|6P58WS2
    -- 263|2021|7|28|10|19|exit|4328GD8
    -- 264|2021|7|28|10|20|exit|G412CB7
    -- 265|2021|7|28|10|21|exit|L93JTIZ
    -- 266|2021|7|28|10|23|exit|322W7JE
    -- 267|2021|7|28|10|23|exit|0NTHK55

    -- Get data from table people whose the license plate is on the query above:
    SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute>=15 AND minute<=25 AND activity="exit" ORDER BY minute ASC);
        -- 221103|Vanessa|(725) 555-4692|2963008352|5P2BI95
        -- 243696|Barry|(301) 555-4174|7526138472|6P58WS2
        -- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ
        -- 398010|Sofia|(130) 555-0289|1695452385|G412CB7
        -- 467400|Luca|(389) 555-5198|8496433585|4328GD8
        -- 514354|Diana|(770) 555-1861|3592750733|322W7JE
        -- 560886|Kelsey|(499) 555-9472|8294398571|0NTHK55
        -- 686048|Bruce|(367) 555-5533|5773159633|94KL13X


-- 4. Gets ATM withdrawal --> BASED ON EUGENE'S INFORMATION
    -- 162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
SELECT * FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street";
    -- 246|28500762|2021|7|28|Leggett Street|withdraw|48
    -- 264|28296815|2021|7|28|Leggett Street|withdraw|20
    -- 266|76054385|2021|7|28|Leggett Street|withdraw|60
    -- 267|49610011|2021|7|28|Leggett Street|withdraw|50
    -- 269|16153065|2021|7|28|Leggett Street|withdraw|80
    -- 288|25506511|2021|7|28|Leggett Street|withdraw|20
    -- 313|81061156|2021|7|28|Leggett Street|withdraw|30
    -- 336|26013199|2021|7|28|Leggett Street|withdraw|35

    --Gets the name of people whose account number is in query above:
    SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street");
    -- 686048
    -- 514354
    -- 458378
    -- 395717
    -- 396669
    -- 467400
    -- 449774
    -- 438727

    -- Gets the name of people whose person_id is in query above:
    SELECT id, name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street"));
    -- 395717|Kenny
    -- 396669|Iman
    -- 438727|Benista
    -- 449774|Taylor
    -- 458378|Brooke
    -- 467400|Luca
    -- 514354|Diana
    -- 686048|Bruce



-- 5. Gets the data BASED ON RAYMOND'S INFORMATION:
    -- 163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

    -- Gets the original flight and destination flight:
    SELECT id FROM airports WHERE city="Fiftyville";

    -- Get the flights id
    SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 1;
        -- 36|4

    -- Get the destination airport city information:
    SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 1);
        -- New York City

    -- Get the passport_number of the people in flights id 36:
    SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 1);

    -- Get the people name and passport number from the flights id 36:
    SELECT name, passport_number FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 1));
        -- Kenny|9878712108
        -- Sofia|1695452385
        -- Taylor|1988161715
        -- Luca|8496433585
        -- Kelsey|8294398571
        -- Edward|1540955065
        -- Bruce|5773159633
        -- Doris|7214083635

    -- Get phone number of a caller and a receiver who made a call on July 28, 2021 around 10 AM from table phone_calls:
    SELECT caller, receiver FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60 ORDER BY duration ASC;
        -- (499) 555-9472|(892) 555-8872
        -- (031) 555-6622|(910) 555-3251
        -- (286) 555-6063|(676) 555-6554
        -- (367) 555-5533|(375) 555-8161
        -- (770) 555-1861|(725) 555-3243
        -- (499) 555-9472|(717) 555-1342
        -- (130) 555-0289|(996) 555-8899
        -- (338) 555-6650|(704) 555-2131
        -- (826) 555-1652|(066) 555-9701

    -- Get the caller name
    SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60 ORDER BY duration ASC);
        -- Kenny|(826) 555-1652
        -- Sofia|(130) 555-0289
        -- Benista|(338) 555-6650
        -- Taylor|(286) 555-6063
        -- Diana|(770) 555-1861
        -- Kelsey|(499) 555-9472
        -- Bruce|(367) 555-5533
        -- Carina|(031) 555-6622

    -- Get the receiver name
    SELECT name, phone_number FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60 ORDER BY duration ASC);
        -- James|(676) 555-6554
        -- Larry|(892) 555-8872
        -- Anna|(704) 555-2131
        -- Jack|(996) 555-8899
        -- Melissa|(717) 555-1342
        -- Jacqueline|(910) 555-3251
        -- Philip|(725) 555-3243
        -- Robin|(375) 555-8161
        -- Doris|(066) 555-9701

-- Gets the name of the person whose phone_number, passport_number and license_plate -> SUSPECTED THIEF:
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60 ORDER BY duration ASC) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 1)) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute>=15 AND minute<=25 AND activity="exit" ORDER BY minute ASC) AND id IN (SELECT id FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street")));
    -- Bruce


-- the accomplice is Robin, we can scroll back to the phone call history and found out that Bruce called Robin