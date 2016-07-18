#Flask study


#Question 

1. what does `@app.cli.command('initdb')` mean here in Step 4? It said 
	> a decorator registers a new command with the flask script. When the command executes, Flask will automatically create an application context for us bound to the right application. Within the function we can then access flask.g and other things as we would expect. When the script ends, the application context tears down and the database connection is released..

   	why need a decorator?

2. same question on `app.teardown_appcontext`, why decorator?
3. why do we need to setup a db file in DATABASE of `app.config`, and schema sql file when opening file.  Why we need to use use two file instead one


#Problems
1. following the official tutorial, can not make a workable web page, always have problems like "can not open database file", or "no entries in database"

Fixed: 1. As I am using windows system Pycharm, the absolute directory need to be stated, and more importantly, escape need to be used in windows directory. `C:\\Users\\AlienLi\\Documents\\GitHub\\python\\flask\\flaskr\\schema.sql` 

And the database file need to produced from schema.sql script first. So go to python
    
    python
    from flaskr import init_db
    init_db()
    
then a database file named flaskr.db will be produced in the same directory.