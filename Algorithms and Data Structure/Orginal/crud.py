#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from pymongo import MongoClient

class AnimalShelter(object):
    """ CRUD operations for the Animal collection in MongoDB """

    def __init__(self, username, password, host, port):
        # string to provide credentials for MongoDB
        self.client = MongoClient(f'mongodb://{username}:{password}@{host}:{port}/?authSource=AAC')
        self.database = self.client['AAC']
        self.collection = self.database['animals']

    # method to insert a document
    def create(self, data):
        if data is not None:
            try:
                self.collection.insert_one(data) 
                return True
            except Exception as e:
                print(f"Error : {e}")
                return False
        else:
            raise Exception("Cannot insert data")

    # method to query documents
    def read(self, query):
        try:
            result = list(self.collection.find(query)) 
            return result
        except Exception as e:
            print(f"Error: {e}")
            return []

    # method to update documents
    def update(self, query, new_values):
        try:
            result = self.collection.update_many(query, {'$set': new_values})
            return result.modified_count
        except Exception as e:
            print(f"Error: {e}")
            return 0

    # method to delete documents
    def delete(self, query):
        try:
            result = self.collection.delete_many(query)
            return result.deleted_count
        except Exception as e:
            print(f"Error: {e}")
            return 0