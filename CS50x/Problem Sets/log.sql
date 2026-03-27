-- Find crime that happened on July 28, 2025 on Humphrey Street
SELECT *
FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Look at interviews on July 28
SELECT *
FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28;

-- Check cars leaving courthouse between 10:15 and 10:25
SELECT *
FROM security_logs
WHERE year = 2025
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;

-- Find people with those license plates
SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM security_logs
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
);

-- ATM withdrawal on Fifer Street
SELECT *
FROM atm_transactions
WHERE year = 2025
AND month = 7
AND day = 28
AND atm_location = 'Fifer Street';

SELECT people.name
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND atm_location = 'Fifer Street'
);

-- Phone calls less than 60 seconds
SELECT *
FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration < 60;

-- Flights on July 29
SELECT *
FROM flights
WHERE year = 2025
AND month = 7
AND day = 29
ORDER BY hour;

SELECT people.name
FROM passengers
JOIN people
ON passengers.passport_number = people.passport_number
WHERE flight_id = (earliest flight id);

