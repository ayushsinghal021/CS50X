-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
select * from crime_scene_reports where day = 28 and month = 7 and year = 2023;
select * from interviews where day = 28 and month = 7 and year = 2023;
select * from bakery_security_logs where day = 28 and month = 7 and year = 2023 and  hour = 10 and activity = 'exit';
select * from people where license_plate in (select license_plate from bakery_security_logs
 where day = 28 and month = 7 and year = 2023 and  hour = 10 and activity = 'exit');
select * from atm_transactions where day = 28 and month = 7 and year = 2023 and atm_location = 'Leggett Street' and transaction_type = 'withdraw';
select person_id from bank_accounts where account_number in (select account_number from atm_transactions where day = 28 and month = 7 and year = 2023 and atm_location = 'Leggett Street' and transaction_type = 'withdraw');
select * from people where id in (select person_id from bank_accounts where account_number
in (select account_number from atm_transactions where day = 28 and month = 7 and year = 2023 and atm_location = 'Leggett Street' and transaction_type = 'withdraw'));
select * from phone_calls where year = 2023 and month = 7 and day = 28 and duration <= 60;
select * from airports;
select * from flights where year = 2023 and month = 7 and day = 29 and origin_airport_id =8 order by hour;
select * from passengers where flight_id = 36;
select * from people where phone_number = '(375) 555-8161';
