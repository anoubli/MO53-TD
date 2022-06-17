/**
 *
 * @file writer.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains writer classes
 * 
 */

//
// Define guards
#ifndef WRITER_H
#define WRITER_H

/**
 * @brief Abstract class (pure virtual) that define the behavior of a writer class
 * 
 */
class writer { // pure virtual
};

/**
 * @brief Class used to write data into text file
 * 
 */
class text_writer : public writer {

};

/**
 * @brief  Class used to write data into text file
 * 
 */
class bin_writer : public writer{

};

#endif // WRITER_H
