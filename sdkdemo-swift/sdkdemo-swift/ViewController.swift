//
//  ViewController.swift
//  sdkdemo-swift
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

import UIKit

import RBSDKPlayer

class ViewController: UIViewController {

    @IBOutlet weak var playerContainerView: UIView?
    var playerController: RBSDKPlayerViewController?
    var bcAccountId: String?

    override func viewDidLoad() {
        super.viewDidLoad()

        self.bcAccountId = "" //TODO: Change this to your Brightcove account id

        RBSDK.sharedInstance().loadAsynchronously { success, error in
            if (success) {
                DispatchQueue.main.async {
                    self.loadPlayerWithMediaIdArray()
//                    self.loadPlayerWithMediaId()
//                    self.loadPlayerWithPlaylistId()
                }

            } else if let error = error {
                print("Error trying to configure the sdk: \(error)")
            }
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()

        if let bounds = playerContainerView?.bounds {
            playerController?.view.frame = bounds
        }
    }

    func loadPlayerWithMediaIdArray() {
        guard let accountId = self.bcAccountId else {
            print("BC Account Id not provided")
            return
        }

        let options: RBSDKPlayerOption = .autoPlay
        let mediaIdArray = ["",
                            "",
                            ""]  //TODO: Change this to a list of Brightcove media ids

        self.playerController = RBSDKBrightcovePlayerViewController(brightcoveMediaIdArray: mediaIdArray,
                                                                    accountId: accountId,
                                                                    options: options)

        self.playerController?.delegate = self

        self.attachPlayerController()
    }

    func loadPlayerWithMediaId() {
        guard let accountId = self.bcAccountId else {
            print("BC Account Id not provided")
            return
        }

        let options: RBSDKPlayerOption = .autoPlay
        let mediaId = "" //TODO: Change this to a Brightcove media id

        self.playerController = RBSDKBrightcovePlayerViewController(brightcoveMediaId: mediaId,
                                                                    accountId: accountId,
                                                                    options: options)

        self.playerController?.delegate = self

        self.attachPlayerController()
    }

    func loadPlayerWithPlaylistId() {
        guard let accountId = self.bcAccountId else {
            print("BC Account Id not provided")
            return
        }

        let options: RBSDKPlayerOption = .autoPlay
        let playlistId = "" //TODO: Change this to a Brightcove playlist id

        self.playerController = RBSDKBrightcovePlayerViewController(brightcovePlaylistId: playlistId,
                                                                    accountId: accountId,
                                                                    options: options)

        self.playerController?.delegate = self

        self.attachPlayerController()
    }

    func attachPlayerController() {
        if let playerController = self.playerController,
            let playerContainerView = self.playerContainerView {

            playerController.view.frame = playerContainerView.bounds
            playerController.view.autoresizingMask = [.flexibleWidth,
                                                      .flexibleHeight]
            playerContainerView.addSubview(playerController.view)
            self.addChildViewController(playerController)
        }
    }
}

// MARK: RBPlayerViewControllerDelegate

extension ViewController: RBSDKPlayerViewControllerDelegate {

    func playerControllerLoadDidSucceed(_ succeed: Bool, withError error: Error?) {
        if (succeed) {
            print("Player load succeed")
        } else if let errorDescription = error?.localizedDescription {
            print("Player was not able to load, error: \(errorDescription)")
        } else {
            print("Player was not able to load")
        }
    }

    func playerControllerCurrentMedia(_ media: RBSDKPlayerMediaInfo?, watchedTime: Float) {
        if let otherParameters = media?.otherParameters {
            print("Other parameters: \(otherParameters)")
        }
    }

}

