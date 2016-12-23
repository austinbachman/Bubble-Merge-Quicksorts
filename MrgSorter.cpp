// Program Information ////////////////////////////////////////////////////////
/**
 * @file MrgSorter.cpp
 *
 * @brief Implementation file for MrgSorter class
 * 
 * @details Implements all member methods of the MrgSorter class
 *
 * @version 1.00 
 *          Austin Bachman (20 February 2016)
 *          Original code
 *
 * @Note Requires MrgSorter.h
 */

#include "MrgSorter.h"
#include <cmath>

/**
 * @brief Default/Initialization MrgSorter constructor
 *
 * @details Constructs MrgSorter with default capacity
 *          
 * @pre assumes Uninitialized MrgSorter object
 *
 * @post List of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
MrgSorter::MrgSorter
   (
   	// no parameters
   )
{
	// parent default constructor called
}

/**
 * @brief Initialization MrgSorter constructor
 *
 * @details Constructs MrgSorter with given capacity
 *          
 * @pre assumes Uninitialized MrgSorter object
 *
 * @post List of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param [in] newCapacity
 *             Desired default or user-provided capacity
 *
 * @return None
 *
 * @note None
 */
MrgSorter::MrgSorter
   (
   	int initialCapacity     // input: capacity to initialize to
   )
       : SorterClass<StudentType>( initialCapacity )
{
	// parent constructor called
}

/**
 * @brief Copy constructor
 *
 * @details Creates local copy of all contents of parameter object
 *          
 * @pre Assumes uninitialized MrgSorter object
 *
 * @par Algorithm 
 *      Calls parent constructor for copy process
 * 
 * @exception None
 *
 * @param [in] copiedVector
 *             Incoming Vector object
 *
 * @return None
 *
 * @note None
 */
MrgSorter::MrgSorter
   (
   	const SorterClass<StudentType> &copiedSorter     // input: vector to copy
   )
       : SorterClass<StudentType>( copiedSorter )
{
	// parent copy constructor called
}

/**
 * @brief Object destructor
 *
 * @details Removes or verifies removal of all data in MrgSorter
 *          
 * @pre Assumes MrgSorter capacity >= 0
 *
 * @par Algorithm
 *      Calls parent destructor
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
MrgSorter::~MrgSorter
   (
    // no parameters
   )
{
  // parent destructor called
}

/**
 * @brief Sort function
 *
 * @details Merge sorts data
 *          
 * @pre Assumes MrgSorter initialized with data
 *
 * @par Algorithm
 *      Calls sortHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
void MrgSorter::sort
   (
    //no parameters
   )
{
    sortHelper( 0, this->getSize() - 1 );
}

/**
 * @brief Merge sorts data in MrgSorter
 *
 * @details Uses merge sorting algorithm to order data
 *          
 * @pre Assumes data found in elements
 *
 * @post All data has been sorted in ascending order
 *
 * @par Algorithm 
 *      Breaks data down recursively, then reorders and
 *      rebuilds list
 * 
 * @exception None
 *
 * @param [in] leftIndex
 *             Index to begin sorting from
 *             
 * @param [in] rightIndex
 *             Index to end sorting at
 *             
 * @return None
 *
 * @note None
 */
void MrgSorter::sortHelper
   (
    int leftIndex,     // input: index to begin group
    int rightIndex     // input: index to end group
   )
{
    int mid = floor( ( leftIndex + rightIndex ) / 2 );

    if( leftIndex < rightIndex )
    {
        sortHelper( leftIndex, mid );
        sortHelper( mid + 1, rightIndex );
        mergeData( leftIndex, mid, rightIndex );
    }
}

/**
 * @brief Merges data in MrgSorter
 *
 * @details Uses merge sorting algorithm to merge data
 *          
 * @pre Assumes data found in elements
 *
 * @post All data has been sorted in ascending order
 *
 * @par Algorithm 
 *      Sorts data into a temp array, then merges back
 *      into original
 * 
 * @exception None
 *
 * @param [in] leftIndex
 *             Index to begin first group from
 *
 * @param [in] middleIndex
 *             Index to end first group and begin second
 *              
 * @param [in] rightIndex
 *             Index to end second group
 *             
 * @return None
 *
 * @note None
 */
void MrgSorter::mergeData
   (
    int leftIndex,       // input: index to begin first group
    int middleIndex,     // input: index to end first group
    int rightIndex       // input: index to end second group
   )
{
    StudentType item1, item2;

    MrgSorter temp( 50 );

    char tmp[50];

    int first1 = leftIndex;
    int last1 = middleIndex;
    int first2 = middleIndex + 1;
    int last2 = rightIndex;

    int index = first1;

    while( (first1 <= last1) && (first2 <= last2) )
    {
        item1 = this->getAtIndex( first1 );
        item2 = this->getAtIndex( first2 );

        if( item1.compareTo( item2 ) <= 0 )
        {
            temp.insertAtIndex( index, item1 );
            first1++;
        }

        else
        {
            temp.insertAtIndex( index, item2 );
            first2++;
        }

        index++;
    }

    while( first1 <= last1 )
    {
        item1 = this->getAtIndex( first1 );
        temp.insertAtIndex( index, item1 );
        first1++;
        index++;
    }

    while( first2 <= last2 )
    {
        item2 = this->getAtIndex( first2 );
        temp.insertAtIndex( index, item2 );
        first2++;
        index++;
    }

    for( index = leftIndex; index <= rightIndex; index++ )
    {
        temp.getAtIndex( index ).toString( tmp );
        this->setAtIndex( index, temp.getAtIndex( index - leftIndex ) );
    }
}